<?hh //strict

/**
 * This file is part of hhpack/service-locator.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\Service;

final class LocatorContext implements Locator {

  private ServiceContainer $container;

  public function __construct(
    Traversable<ServiceFactory> $factories = [],
  ) {
    $this->container = new ServiceContainer($factories);
  }

  public function lookup<Tu as this::T>(classname<Tu> $name): Tu {
    $service = $this->lookupByName((string) $name);

    if (!($service instanceof $name)) {
      throw new InvalidServiceException(
        "It is not in the service $name are expecting",
      );
    }

    return $service;
  }

  public static function fromItems(
    Traversable<ServiceFactory> $factories = [],
  ): this {
    return new static($factories);
  }

  private function lookupByName(string $name): this::T {
    $factory = $this->container->lookup($name);
    return $factory->createService($this);
  }

}
