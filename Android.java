// called when back, not called when home, sometimes called when killed in recent task.
onDestroy

// called when back, home and recent task
onStop


// 枚举：
public enum PacketType {
	VehicleLogin((byte) 0),
	VehicleRealtimeUpload((byte) 1),
	ReissueUpload((byte) 2),
	VehicleLogout((byte) 3),
	PlatformLogin((byte) 4),
	PlatformLogout((byte) 5);

	private final byte value;
	private static final PacketType[] TypeArray = {VehicleLogin, 
		VehicleRealtimeUpload, ReissueUpload, VehicleLogout, PlatformLogin, PlatformLogout};
	private PacketType(byte value) {
		this.value = value;
	}

	public byte value() {
		return value;
	}
	
	public static PacketType type(byte v) {
		return TypeArray[v];
	}
}
// usage:
	byte b = (byte)1;
	PacketType packetType = PacketType.type(b);
	System.out.println(packetType);
