<?hh //strict

namespace hhpack\servicelocator;

use ReflectionMethod;
use LogicException;

final class ServiceContainer
{

    private ImmMap<string, ServiceFactory<Service>> $factories;

    public function __construct(
        Traversable<ServiceFactory<Service>> $factories = []
    )
    {
        $this->factories = $this->mapping($factories);
    }

    public function lookup(string $name) : ServiceFactory<Service>
    {
        $factory = $this->factories->at($name);
        return $factory;
    }

    private function mapping(Traversable<ServiceFactory<Service>> $factories) : ImmMap<string, ServiceFactory<Service>>
    {
        $items = ImmVector::fromItems($factories)
            ->map(($factory) ==> $this->pairOfFactory($factory));

        return ImmMap::fromItems($items);
    }

    private function pairOfFactory(ServiceFactory<Service> $factory) : Pair<string, ServiceFactory<Service>>
    {
        $method = new ReflectionMethod($factory, 'createService');
        $type = $method->getReturnType();

        if ($type === null) {
            throw new LogicException();
        }

        return Pair { (string) $type, $factory };
    }

}
