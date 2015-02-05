Pod::Spec.new do |s|

  s.name         = "BeeCloud"
  s.version      = "2.1"
  s.summary      = "BeeCloud云服务 致力加速App 开发"

  s.homepage     = "http://beecloud.cn"

  s.license      = {:type => 'MIT'}

  s.author       = "http://beecloud.cn"

  s.platform     = :ios

  s.source       = { :git =>"https://github.com/beecloud/beecloud-sdk.git", :tag => 'v2.1.0'}
  s.source_files  = "iOS/v2.1/BeeCloud.framework/*", "iOS/v2.1/BeeCloud.framework/**/*"

  s.frameworks  = "CoreGraphics","CoreLocation","MobileCoreServices","Security","SystemConfiguration","UIKit","CoreTelephony"
  s.libraries    = "sqlite3","c++","z"

  s.requires_arc = true

end
