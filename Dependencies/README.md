# External dependencies

## Dependencies description

* **Joystick_drivers**: Let's the user run nodes such that a controller will automatically get registered and recieve streamed data through serial.

* **depthai-core**: Physical library with headers required for Luxonis Camera interfacing.

## How to add an external repository to github

Within the folder `~/hugr_optimus/Dependencies/`, use:

```bash
git submodule add https://github.com/<user>/<repo>
```

(after `add`, use the HTTPS link to the repository)

If github does not download the submodule directly, use:

```bash
git submodule update --init --recursive
```

## Activating ROS dependencies

To add more ROS dependencies to the Sentral Board Computer (SBC) you may edit the `init.sh` and add another line with the bash command required to download the aforementioned dependency. For example:

```bash
vim init.sh
# Write in dependency
sudo apt install -y <dependency>
```

To run the install script simply `source` it:

```bash
cd ~/hugr_optimus/Dependencies/
source init.sh
```
