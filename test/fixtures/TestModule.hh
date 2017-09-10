<?hh //strict

namespace HHPack\Service\Test\Fixtures;

use HHPack\Service\{
  Service,
  Locator,
  LocatorContext,
  FactoryModule,
  ServiceFactory
};

final class TestModule implements FactoryModule {

  public function getIterator(): Iterator<ServiceFactory<Service>> {
    yield new LoggerFactory();
  }

}
