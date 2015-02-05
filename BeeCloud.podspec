Pod::Spec.new do |s|

  s.name         = "BeeCloud"
  s.version      = "2.1"
  s.summary      = "BeeCloud云服务 致力加速App 开发"

  s.homepage     = "http://beecloud.cn"

  s.license      = "MIT"

  s.author       = "http://beecloud.cn"

  s.platform     = :ios

  s.source       = { :git =>"https://github.com/beecloud/beecloud-sdk.git", :tag => 'v2.1'}
  s.source_files  = "iOS/v2.1/BeeCloud.framework/*"
  #s.source       = { :http => "http://beecloud.cn/download/file/BeeCloud.framework.v2.1.zip"}

  s.frameworks  = "CoreGraphics","CoreLocation","MobileCoreServices","Security","SystemConfiguration","UIKit","CoreTelephony"

  s.requires_arc = true

end
