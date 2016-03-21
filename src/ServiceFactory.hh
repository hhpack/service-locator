<?hh //strict

namespace hhpack\servicelocator;

interface ServiceFactory<+T as Service>
{
    public function createService() : T;
}
