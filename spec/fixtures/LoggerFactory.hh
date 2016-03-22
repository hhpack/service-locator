<?hh //strict

namespace hhpack\service\spec\fixtures;

use hhpack\service\ServiceFactory;

final class LoggerFactory implements ServiceFactory<Logger>
{
    public function createService() : Logger
    {
        return new Logger();
    }
}
