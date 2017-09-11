<?hh //strict

namespace HHPack\Service\Test\Fixtures;

use HHPack\Service\{Module, ServiceFactory};

final class TestModule implements Module {

  public function getIterator(): Iterator<ServiceFactory> {
    yield new LoggerFactory();
  }

}
