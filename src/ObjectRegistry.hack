/**
 * This file is part of hhpack/service-locator.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace HHPack\ServiceLocator;

use Countable;

interface ObjectRegistry extends Countable {

  abstract const type T;

  // From ConstCollection<+Te> excluding toDArray / toVArray methods
  public function isEmpty(): bool;
  public function count(): int;
  public function items(): Iterable<Pair<string, this::T>>;

  public function lookup(string $name): this::T;
}
