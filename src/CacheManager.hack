/**
 * This file is part of hhpack/service-locator.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\ServiceLocator;

interface CacheManager {
  abstract const type T;
  public function has<Tu as this::T>(classname<Tu> $name): bool;
  public function get<Tu as this::T>(classname<Tu> $name): Tu;
  public function set<Tu as this::T>(classname<Tu> $name, Tu $service): void;
}
