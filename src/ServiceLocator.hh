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

final class ServiceLocator implements Locator<Service> {

  private CacheManager $cacheManager;

  public function __construct(private Locator<Service> $context) {
    $this->cacheManager = new CacheContainer();
  }

  public function lookup<Tu as Service>(classname<Tu> $name): Tu {
    if ($this->cacheManager->has($name)) {
      return $this->cacheManager->get($name);
    }
    $service = $this->context->lookup($name);
    $this->cacheManager->set($name, $service);

    return $service;
  }

  public static function fromItems(
    Traversable<ServiceFactory<Service>> $factories = [],
  ): this {
    return new static(new LocatorContext($factories));
  }

  public static function fromModuleName(
    classname<FactoryModule> $module,
  ): this {
    $reflection = new \ReflectionClass($module);
    return static::fromModule($reflection->newInstance());
  }

  public static function fromModule(FactoryModule $module): this {
    return static::fromItems($module);
  }

}
