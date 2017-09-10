<?hh //strict

namespace HHPack\Service;

final class LocatorContext implements Locator<Service> {

  private ServiceContainer $container;

  public function __construct(
    Traversable<ServiceFactory<Service>> $factories = [],
  ) {
    $this->container = new ServiceContainer($factories);
  }

  public function lookup<Tu as Service>(classname<Tu> $name): Tu {
    $service = $this->lookupByName((string) $name);

    if (!($service instanceof $name)) {
      throw new InvalidServiceException(
        "It is not in the service $name are expecting",
      );
    }

    return $service;
  }

  public static function fromItems(
    Traversable<ServiceFactory<Service>> $factories = [],
  ): this {
    return new static($factories);
  }

  private function lookupByName(string $name): Service {
    $factory = $this->container->lookup($name);
    return $factory->createService($this);
  }

}
