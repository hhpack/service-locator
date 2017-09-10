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

use IteratorAggregate;

interface FactoryModule
  extends
    IteratorAggregate<ServiceFactory<Service>>,
    Traversable<ServiceFactory<Service>> {
  public function getIterator(): Iterator<ServiceFactory<Service>>;
}
