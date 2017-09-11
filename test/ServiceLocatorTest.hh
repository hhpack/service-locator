<?hh //strict

namespace HHPack\Service\Test;

use HHPack\Service\{ServiceLocator};
use HHPack\Service\Test\Fixtures\{
  TestModule,
  Logger,
  LoggerFactory,
  HttpClient,
  HttpClientFactory
};
use HackPack\HackUnit\Contract\Assert;

final class ServiceLocatorTest {

  public function __construct(private ServiceLocator $locator) {}

  <<SuiteProvider('Factories')>>
  public static function createByItems(): this {
    $locator = ServiceLocator::fromItems(
      [new LoggerFactory(), new HttpClientFactory()],
    );
    return new static($locator);
  }

  <<SuiteProvider('TestModule')>>
  public static function createByModule(): this {
    $locator = ServiceLocator::fromModuleName(TestModule::class);
    return new static($locator);
  }

  <<Test('Factories')>>
  public function lookupByClassName(Assert $assert): void {
    $assert->mixed($this->locator->lookup(Logger::class))
      ->isTypeOf(Logger::class);
    $assert->mixed($this->locator->lookup(HttpClient::class))
      ->isTypeOf(HttpClient::class);
  }

  <<Test('TestModule')>>
  public function fromModuleName(Assert $assert): void {
    $assert->mixed($this->locator->lookup(Logger::class))
      ->isTypeOf(Logger::class);
  }
}
