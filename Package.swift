// swift-tools-version:5.9
import PackageDescription

let package = Package(
  name: "MediaMelonQoE",
  platforms: [
    .iOS(.v12),
    .tvOS(.v12),
    .visionOS(.v2)
  ],
  products: [
    .library(
      name: "MediaMelonQoE",
      targets: ["MediaMelonQoE"]
    )
  ],
  targets: [
    .binaryTarget(
      name: "MediaMelonQoE",
      path: "./MediaMelonQoE.xcframework"
    )
  ]
)