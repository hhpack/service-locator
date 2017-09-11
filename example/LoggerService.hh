<?hh //strict

namespace HHPack\ServiceLocator\Example;

use HHPack\ServiceLocator\Service;

final class LoggerService implements Logger {

  public function __construct(private string $prefix) {}

  public function put(string $message): void {
    fwrite(STDOUT, $this->prefix." - ".$message."\n");
  }

}
