<?hh //strict

namespace hhpack\servicelocator\spec\fixtures;

use hhpack\servicelocator\ServiceFactory;

final class LoggerFactory implements ServiceFactory<Logger>
{
    public function createService() : Logger
    {
        return new Logger();
    }
}
