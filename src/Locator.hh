<?hh //strict

namespace HHPack\Service;

interface Locator<T>
{
    public function lookup<Tu as T>(classname<Tu> $name) : Tu;
}
