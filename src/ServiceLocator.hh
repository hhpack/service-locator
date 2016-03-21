<?hh //strict

namespace hhpack\servicelocator;

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

    public static function fromItems(Traversable<Pair<string, ServiceFactory<Service>>> $factories = []) : this
    {
        return new static(new LocatorContext($factories));
    }

}
