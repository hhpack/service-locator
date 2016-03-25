<?hh //strict

namespace hhpack\service\example;

use hhpack\service\Service;

interface Logger extends Service
{
    public function put(string $message) : void;
}
