<?hh //strict

namespace hhpack\service;

interface KeyAccess<T>
{
    public function lookup(string $name) : T;
}
