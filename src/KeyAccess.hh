<?hh //strict

namespace HHPack\Service;

interface KeyAccess<T> {
  public function lookup(string $name): T;
}
