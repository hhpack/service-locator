<?hh //strict

namespace hhpack\service;

interface Locator<T>
{
    public function lookup<Tu as T>(classname<Tu> $name) : Tu;
}
