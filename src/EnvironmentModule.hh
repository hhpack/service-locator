<?hh //strict

namespace HHPack\Service;

use HHPack\Package as package;
use HHPack\Package\VendorPackage;
use RuntimeException;

final class EnvironmentModule implements FactoryModule
{

    private VendorPackage $package;

    public function __construct(Traversable<Pair<string, string>> $namespaces)
    {
        $this->package = VendorPackage::fromItems($namespaces);
    }

    public function getIterator() : Iterator<ServiceFactory<Service>>
    {
        $environment = getenv('HHVM_ENV') ? getenv('HHVM_ENV') : 'development';

        $module = $this->package->classes(package\implementsInterface(FactoryModule::class))
            ->filter(package\startsWith(ucfirst($environment)))
            ->firstValue();

        if ($module === null) {
            throw new RuntimeException("Module not found for $environment");
        }

        return $module->instantiate()->getIterator();
    }

}
