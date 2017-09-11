<?hh //strict

/**
 * This file is part of hhpack/service-locator.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\ServiceLocator;

use HHPack\ServiceLocator\Cache\{CacheContainer};
use HHPack\ServiceLocator\Registry\{ServiceRegistry};

final class ServiceLocator implements Locator {
  const type T = Service;

  private CacheContainer $cacheManager;

  public function __construct(private ServiceRegistry $container) {
    $this->cacheManager = new CacheContainer();
  }

  public function lookup<Tu as this::T>(classname<Tu> $name): Tu {
    if ($this->cacheManager->has($name)) {
      return $this->cacheManager->get($name);
    }

    $service = $this->lookupByName((string) $name);

    if (!($service instanceof $name)) {
      throw new InvalidServiceException(
        "It is not in the service $name are expecting",
      );
    }

    $this->cacheManager->set($name, $service);

    return $service;
  }

  private function lookupByName(string $name): this::T {
    $factory = $this->container->lookup($name);
    return $factory->createService($this);
  }

  public static function fromItems(
    Traversable<ServiceFactory> $factories = [],
  ): this {
    return new static(new ServiceRegistry($factories));
  }

  public static function fromModuleName(classname<Module> $module): this {
    $reflection = new \ReflectionClass($module);
    return static::fromModule($reflection->newInstance());
  }

  public static function fromModule(Module $module): this {
    return static::fromItems($module);
  }

}
