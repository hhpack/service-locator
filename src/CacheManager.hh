<?hh //strict

namespace hhpack\service;

interface CacheManager
{
    public function has<Tu as Service>(classname<Tu> $name) : bool;
    public function lookup<Tu as Service>(classname<Tu> $name) : Tu;
}
