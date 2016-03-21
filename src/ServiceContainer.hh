<?hh //strict

namespace hhpack\servicelocator;

final class ServiceContainer
{

    private ImmMap<string, ServiceFactory<Service>> $factories;

    public function __construct(
        Traversable<Pair<string, ServiceFactory<Service>>> $factories = []
    )
    {
        $this->factories = ImmMap::fromItems($factories);
    }

    public function lookup(string $name) : ServiceFactory<Service>
    {
        $factory = $this->factories->at($name);
        return $factory;
    }

}
