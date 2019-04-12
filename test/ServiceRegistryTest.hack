namespace HHPack\ServiceLocator\Test;

use HHPack\ServiceLocator\Registry\{ServiceRegistry};
use HHPack\ServiceLocator\Test\Fixtures\{
  Logger,
  LoggerFactory,
  HttpClient,
  HttpClientFactory,
};
use type Facebook\HackTest\{HackTest, DataProvider};
use function Facebook\FBExpect\expect;

final class ServiceRegistryTest extends HackTest {
  public function provideFactories(): vec<(ServiceRegistry)> {
    return vec[tuple(
      new ServiceRegistry([new LoggerFactory(), new HttpClientFactory()]),
    )];
  }

  <<DataProvider('provideFactories')>>
  public function testContainer(ServiceRegistry $container): void {
    expect($container->count())->toBeSame(2);
    expect($container->isEmpty())->toBeFalse();

    $items = ImmMap::fromItems($container->items());
    expect($container->count())->toBeSame(2);
  }

  <<DataProvider('provideFactories')>>
  public function testLookupByClassNameString(
    ServiceRegistry $container,
  ): void {
    expect($container->lookup((string)Logger::class))->toBeInstanceOf(
      LoggerFactory::class,
    );
    expect($container->lookup((string)HttpClient::class))->toBeInstanceOf(
      HttpClientFactory::class,
    );
  }
}
