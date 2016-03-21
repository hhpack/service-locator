<?hh //strict

namespace hhpack\servicelocator;

use LazyIterable;
use ReflectionMethod;
use LogicException;

final class FactoryContainer implements FactoryIterable
{

    use LazyIterable<ServiceFactory<Service>>;

    private ImmVector<ServiceFactory<Service>> $factories;

    public function __construct(
        Traversable<ServiceFactory<Service>> $factories = []
    )
    {
        $this->factories = ImmVector::fromItems($factories);
    }

    public function getIterator() : Iterator<ServiceFactory<Service>>
    {
        return $this->factories->getIterator();
    }

    public function toImmMap() : ImmMap<string, ServiceFactory<Service>>
    {
        $factories = $this->factories
            ->map(($factory) ==> $this->pairOfFactory($factory));
        return ImmMap::fromItems($factories);
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
