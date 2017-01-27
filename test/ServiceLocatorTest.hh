<?hh //strict

namespace HHPack\Service\Test;

use HHPack\Service\ServiceLocator;
use HHPack\Service\LocatorContext;
use HHPack\Service\Test\Fixtures\TestModule;
use HHPack\Service\Test\Fixtures\Logger;
use HHPack\Service\Test\Fixtures\LoggerFactory;
use HHPack\Service\Test\Fixtures\HttpClient;
use HHPack\Service\Test\Fixtures\HttpClientFactory;
use HackPack\HackUnit\Contract\Assert;

final class ServiceLocatorTest
{
    <<Test>>
    public function lookupByClassName(Assert $assert): void
    {
        $locator = ServiceLocator::fromItems([
            new LoggerFactory(),
            new HttpClientFactory()
        ]);
        $assert->mixed($locator->lookup(Logger::class))->isTypeOf(Logger::class);
        $assert->mixed($locator->lookup(HttpClient::class))->isTypeOf(HttpClient::class);
    }

    <<Test>>
    public function fromModuleName(Assert $assert): void
    {
        $locator = ServiceLocator::fromModuleName(TestModule::class);
        $assert->mixed($locator->lookup(Logger::class))->isTypeOf(Logger::class);
    }
}
