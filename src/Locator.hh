<?hh //strict

namespace hhpack\servicelocator;

interface Locator<T>
{
    public function lookup<Tu as T>(classname<Tu> $name) : Tu;
}
