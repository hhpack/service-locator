<?hh //strict

namespace HHPack\ServiceLocator\Example;

use HHPack\ServiceLocator\Service;

interface Logger extends Service {
  public function put(string $message): void;
}
