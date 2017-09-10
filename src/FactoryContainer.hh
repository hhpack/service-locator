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

use ConstCollection;

interface FactoryContainer
  extends
    KeyAccess<ServiceFactory<Service>>,
    ConstCollection<Pair<string, ServiceFactory<Service>>> {
  public function lookup(string $name): ServiceFactory<Service>;
}
