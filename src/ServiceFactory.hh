<?hh //strict

namespace hhpack\service;

interface ServiceFactory<+T as Service>
{
    public function createService() : T;
}
