import speedtest

def test_speed():
    print("Testing your speed...")
    speed_test = speedtest.Speedtest()
    download_speed = speed_test.download()
    upload_speed = speed_test.upload()
    download_speed_mbs = round(download_speed / (10**6), 2)
    upload_speed_mbs = round(upload_speed / (10**6), 2)
    print(f"Download speed: {download_speed_mbs} Mbps")
    print(f"Upload speed: {upload_speed_mbs} Mbps")

command = ""
while command != "stop":
    command = input("Type 'stop' to exit or press Enter to test your speed: ")
    if command != "stop":
        test_speed()