<?hh //partial

use expect\peridot\ExpectPlugin;
use Evenement\EventEmitterInterface;
use Peridot\Reporter\Dot\DotReporterPlugin;

return function(EventEmitterInterface $emitter)
{
    ExpectPlugin::create()->registerTo($emitter);
    (new DotReporterPlugin($emitter));
};
