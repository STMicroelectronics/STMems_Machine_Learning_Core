import os
import logging


class Logger:

    def __init__(self, current_dir, tag):
        self.current_directory = current_dir
        self.tag = tag
        log_filename = os.path.join(current_dir, "log.txt")

        for handler in logging.root.handlers:
            logging.root.removeHandler(handler)

        logging.basicConfig(
            level=logging.INFO,
            format="%(asctime)s [%(levelname)s] %(message)s",
            handlers=[
                logging.FileHandler(log_filename),
                logging.StreamHandler(),
            ],
        )
