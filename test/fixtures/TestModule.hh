<?hh //strict

namespace HHPack\ServiceLocator\Test\Fixtures;

use HHPack\ServiceLocator\{Module, ServiceFactory};

final class TestModule implements Module {

  public function getIterator(): Iterator<ServiceFactory> {
    yield new LoggerFactory();
  }

}
