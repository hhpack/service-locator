<?hh //strict

namespace hhpack\servicelocator;

interface KeyAccess<T>
{
    public function lookup(string $name) : T;
}
