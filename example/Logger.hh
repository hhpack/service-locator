<?hh //strict

namespace HHPack\Service\Example;

use HHPack\Service\Service;

interface Logger extends Service
{
    public function put(string $message) : void;
}
