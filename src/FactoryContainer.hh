<?hh //strict

namespace hhpack\servicelocator;

use ConstCollection;

interface FactoryContainer extends KeyAccess<ServiceFactory<Service>>, ConstCollection<Pair<string, ServiceFactory<Service>>>
{
    public function lookup(string $name) : ServiceFactory<Service>;
}
