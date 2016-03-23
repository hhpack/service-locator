<?hh //strict

namespace hhpack\service;

use ReflectionMethod;
use LogicException;
use OutOfBoundsException;

final class ServiceContainer implements FactoryContainer
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
        try {
            $factory = $this->factories->at($name);
        } catch (OutOfBoundsException $reason) {
            throw new ServiceNotRegisteredException("The service $name is not registered", 0, $reason);
        }

        return $factory;
    }

    public function count() : int
    {
        return $this->factories->count();
    }

    public function isEmpty() : bool
    {
        return $this->factories->isEmpty();
    }

    public function items() : Iterable<Pair<string, ServiceFactory<Service>>>
    {
        return $this->factories->items();
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
