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

use ConstCollection;

interface ObjectRegistry extends ConstCollection<Pair<string, this::T>> {

  abstract const type T;
  public function lookup(string $name): this::T;
}
