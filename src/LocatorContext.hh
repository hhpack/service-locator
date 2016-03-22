<?hh //strict

namespace hhpack\servicelocator;

final class LocatorContext implements Locator<Service>
{

    private ServiceContainer $container;

    public function __construct(
        Traversable<ServiceFactory<Service>> $factories = []
    )
    {
        $this->container = new ServiceContainer($factories);
    }

    public function lookup<Tu as Service>(classname<Tu> $name) : Tu
    {
        $service = $this->lookupByName((string) $name);

        if (!($service instanceof $name)) {
            throw new InvalidServiceException("It is not in the service $name are expecting");
        }

        return $service;
    }

    private function lookupByName(string $name) : Service
    {
        $factory = $this->container->lookup($name);
        return $factory->createService();
    }

}
