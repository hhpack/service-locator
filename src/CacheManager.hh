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

interface CacheManager {
  public function has<Tu as Service>(classname<Tu> $name): bool;
  public function get<Tu as Service>(classname<Tu> $name): Tu;
  public function set<Tu as Service>(classname<Tu> $name, Tu $service): void;
}
