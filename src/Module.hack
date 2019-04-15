/**
 * This file is part of hhpack/service-locator.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\ServiceLocator;

use HHPack\ServiceLocator\{ServiceFactory};
use IteratorAggregate;

interface Module extends IteratorAggregate<this::T> {
  const type T = ServiceFactory;
  public function getIterator(): Iterator<this::T>;
}
