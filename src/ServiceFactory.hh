<?hh //strict

namespace HHPack\Service;

interface ServiceFactory<+T as Service> {
  public function createService(Locator<Service> $locator): T;
}
