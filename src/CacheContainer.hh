<?hh //strict

namespace hhpack\service;

use OutOfBoundsException;

final class CacheContainer implements CacheManager
{

    private Map<string, Service> $services;

    public function __construct()
    {
        $this->services = Map {};
    }

    public function has<Tu as Service>(classname<Tu> $name) : bool
    {
        return $this->services->containsKey((string) $name);
    }

    public function get<Tu as Service>(classname<Tu> $name) : Tu
    {
        $service = $this->services->at((string) $name);

        if (!($service instanceof $name)) {
            throw new InvalidServiceException("It is not in the service $name are expecting");
        }

        return $service;
    }

    public function set<Tu as Service>(classname<Tu> $name, Tu $service) : void
    {
        $this->services->set((string) $name, $service);
    }

}
