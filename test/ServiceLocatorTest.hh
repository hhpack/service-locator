<?hh //strict

namespace HHPack\ServiceLocator\Test;

use HHPack\ServiceLocator\{ServiceLocator};
use HHPack\ServiceLocator\Test\Fixtures\{
  TestModule,
  Logger,
  LoggerFactory,
  HttpClient,
  HttpClientFactory,
};
use type Facebook\HackTest\HackTest;
use function Facebook\FBExpect\expect;

final class ServiceLocatorTest extends HackTest {
  public function provideFactories(): vec<(ServiceLocator)> {
    return vec[tuple(
      ServiceLocator::fromItems([new LoggerFactory(), new HttpClientFactory()]),
    )];
  }

  public function provideByModule(): vec<(ServiceLocator)> {
    return vec[tuple(ServiceLocator::fromModuleName(TestModule::class))];
  }

  <<DataProvider('provideFactories')>>
  public function testLookupByClassName(ServiceLocator $locator): void {
    expect($locator->lookup(Logger::class))->toBeInstanceOf(Logger::class);
    expect($locator->lookup(HttpClient::class))->toBeInstanceOf(
      HttpClient::class,
    );
  }

  <<DataProvider('provideByModule')>>
  public function testFromModuleName(ServiceLocator $locator): void {
    expect($locator->lookup(Logger::class))->toBeInstanceOf(Logger::class);
  }
}
