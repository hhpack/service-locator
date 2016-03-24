<?hh //strict

namespace hhpack\service;

final class ServiceLocator implements Locator<Service>
{

    public function __construct(
        private Locator<Service> $context
    )
    {
    }

    public function lookup<Tu as Service>(classname<Tu> $name) : Tu
    {
        return $this->context->lookup($name);
    }

    public static function fromItems(Traversable<ServiceFactory<Service>> $factories = []) : this
    {
        return new static(new LocatorContext($factories));
    }

    public static function fromModule(classname<FactoryModule> $module) : this
    {
        $reflection = new \ReflectionClass($module);
        return static::fromItems( $reflection->newInstance() );
    }

}
