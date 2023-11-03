# Billboard Wi-Fi

The billboard Wi-Fi was hosted by an Asus Router that I bought at a local thrift store for $20.00

- Asus Router - RT-AC3200
- Open Wi-Fi, no security or password
- Router IP: 192.168.42.1
- Admin interface: https://192.168.42.1:8443 
- ESSID: EAZYBillboardsLtd
- DHCP: 192.168.42.10 to 192.168.42.250

After a factory reset, it was configured as above, with a few additional hardening steps taken:

- To perform a full factory reset - power off, hold down WPS button on back, power on, release WPS button when power LED flashes
- Default IP address: 192.168.1.1
- Default UID/PWD: admin/admin
- Change admin password
- Router IP
- ESSID
- DHCP
- Disable WPS - Wireless, WPS tab
- Enable HTTPS for Admin interface - Administration, System tab
- Disable Media Server, Network Sharing - USB Application tabs
