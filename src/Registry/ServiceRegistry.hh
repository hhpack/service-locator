<?hh //strict

/**
 * This file is part of hhpack/service-locator.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\ServiceLocator\Registry;

use HHPack\ServiceLocator\{ObjectRegistry, ServiceFactory};
use ReflectionClass;
use LogicException;
use OutOfBoundsException;

final class ServiceRegistry implements ObjectRegistry {
  const type T = ServiceFactory;

  private ImmMap<string, this::T> $factories;

  public function __construct(Traversable<this::T> $factories = []) {
    $this->factories = $this->mapping($factories);
  }

  public function lookup(string $name): this::T {
    try {
      $factory = $this->factories->at($name);
    } catch (OutOfBoundsException $reason) {
      throw new ServiceNotRegisteredException(
        "The service $name is not registered",
        0,
        $reason,
      );
    }

    return $factory;
  }

  public function count(): int {
    return $this->factories->count();
  }

  public function isEmpty(): bool {
    return $this->factories->isEmpty();
  }

  public function items(): Iterable<Pair<string, this::T>> {
    return $this->factories->items();
  }

  private function mapping(
    Traversable<this::T> $factories,
  ): ImmMap<string, this::T> {
    $items =
      ImmVector::fromItems($factories)
        ->map(($factory) ==> $this->pairOfFactory($factory));

    return ImmMap::fromItems($items);
  }

  private function pairOfFactory(this::T $factory): Pair<string, this::T> {
    $class = new ReflectionClass($factory);
    $type = $class->getTypeConstant('T')->getAssignedTypeText();

    if ($type === null) {
      throw new LogicException('The return value can not be void');
    }

    return Pair {(string) $type, $factory};
  }

}
