<?hh //strict

namespace hhpack\service\example;

use hhpack\service\Service;

final class LoggerService implements Logger
{

    public function __construct(private string $prefix)
    {
    }

    public function put(string $message) : void
    {
        fwrite(STDOUT, $this->prefix . " - " . $message . "\n");
    }

}
