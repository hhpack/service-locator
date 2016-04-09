<?hh //strict

namespace hhpack\service;

interface CacheManager
{
    public function has<Tu as Service>(classname<Tu> $name) : bool;
    public function get<Tu as Service>(classname<Tu> $name) : Tu;
    public function set<Tu as Service>(classname<Tu> $name, Tu $service) : void;
}
