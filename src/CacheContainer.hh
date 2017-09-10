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

use OutOfBoundsException;

final class CacheContainer implements CacheManager {

  const type T = Service;

  private Map<string, this::T> $services;

  public function __construct() {
    $this->services = Map {};
  }

  public function has<Tu as this::T>(classname<Tu> $name): bool {
    return $this->services->containsKey((string) $name);
  }

  public function get<Tu as this::T>(classname<Tu> $name): Tu {
    $service = $this->services->at((string) $name);

    if (!($service instanceof $name)) {
      throw new InvalidServiceException(
        "It is not in the service $name are expecting",
      );
    }

    return $service;
  }

  public function set<Tu as this::T>(classname<Tu> $name, Tu $service): void {
    $this->services->set((string) $name, $service);
  }

}
